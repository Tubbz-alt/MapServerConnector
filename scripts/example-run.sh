#!/bin/sh

#  Check valgrind
#VALGRIND_ARGS='valgrind'

./src/apps/image-fetcher/image-fetcher ../data/Configuration.ogc.cfg output.png $@

