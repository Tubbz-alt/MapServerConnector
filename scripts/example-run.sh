#!/bin/sh

#  Check valgrind
VALGRIND_ARGS=''
GDB_ARGS='--args'

PRE_CMD=''

for ARG in "$@"; do

    case $ARG in

        #  Check if Valgrind Requested
        '-valgrind')
            PRE_CMD="$PRE_CMD valgrind $VALGRIND_ARGS"
            ;;

        #  Check if GDB requested
        '-gdb')
            PRE_CMD="$PRE_CMD gdb $GDB_ARGS"
            ;;

    esac

done

#  Create command
CMD="$PRE_CMD ./src/apps/image-fetcher/image-fetcher ../data/Configuration.ogc.cfg output.png"

#  Print and execute
echo $CMD
$CMD

