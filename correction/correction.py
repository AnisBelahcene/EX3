"""Correction script for this exercise.
- compiles test.c
For each depot name found in depots.txt:
- clones the repo.
- invokes 'make build/libliste.a'.
- links test.o with libliste.a into a program test.
- prints the return code of test or a negative value if an earlier error occured:
    - -1: failed to clone the repo.
    - -3: failed to compile.
    - -4: failed to parse results (i.e. couldn't find "M/N" test results line) in time.
"""

import itertools
import os
import re
import subprocess

import pygit2

CALLBACKS = pygit2.RemoteCallbacks(credentials=pygit2.KeypairFromAgent("git"))

os.system('gcc -g -c ../test/main.c -I ../lib -o main.o')

with open('depots.txt') as remote_depot_names:
    for remote_depot_name in itertools.dropwhile(lambda line: line.startswith('#'),
                                                 remote_depot_names):
        try:
            # Craft URL to clone given a depot name.
            remote_depot_name = remote_depot_name.rstrip()
            remote_depot_url = 'ssh://git@github.com/' + remote_depot_name + '.git'
            local_depot_path = remote_depot_name.replace('/', '-')
            print(local_depot_path, end=' ')

            # Clone the repo.
            if pygit2.clone_repository(remote_depot_url, local_depot_path, callbacks=CALLBACKS) \
                    is None:
                raise RuntimeError('-1')

           # Compile libliste.a and link with main.o.
            if os.system('cd ' + local_depot_path + ' && make build/libliste.a') != 0 or \
               os.system('gcc main.o -L ' + local_depot_path + '/build -l liste -o ' + local_depot_path + \
                         '/build/test'):
                raise RuntimeError('-3')

            # Run and capture test results (i.e. "M/N").
            pipe = subprocess.Popen(['correction/' + local_depot_path + '/build/test'], stdout=subprocess.PIPE, \
                                    stderr=subprocess.PIPE, cwd='..', )
            out, err = pipe.communicate(timeout=3)
            results = re.search(r'^\d+/\d+$', out.decode(), re.MULTILINE)
            if results is None:
                raise RuntimeError('-4')
            print(results.group(0))
        except pygit2.GitError:
            print('-1')
        except RuntimeError as error:
            print(error.args[0])
        except TimeoutError as error:
            print('-4')
            pipe.kill()
            pipe.communicate()
