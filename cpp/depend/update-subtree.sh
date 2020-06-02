#!/bin/bash
# This command pulls the latest updates from the master branch of the subtrees.
# See man git-subtree(1) for more details.
git subtree pull --prefix cpp/depend/benchmark https://github.com/google/benchmark.git master --squash
git subtree pull --prefix cpp/depend/benchmark/googletest https://github.com/google/googletest.git master --squash
