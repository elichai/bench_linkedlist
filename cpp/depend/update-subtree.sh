#!/bin/bash
# This command pulls the latest updates from the master branch of the subtree and commits them in depend/secp256k1.
# See man git-subtree(1) for more details.
git subtree pull --prefix cpp/depend/benchmark https://github.com/google/benchmark.git master --squash
