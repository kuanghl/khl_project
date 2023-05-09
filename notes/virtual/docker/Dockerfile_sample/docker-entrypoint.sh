#!/usr/bin/env bash
set -Eeuo pipefail

# first arg is `-f` or `--some-option`
# or there are no args
if [ "$#" -eq 0 ] 
	[ "${1#-}" != "$1" ]; then
	
	# docker run bash -c 'echo hi'
	# $ winpty docker run -it docker_file:test -c 'echo hi docker'	

	exec bash "$@"
fi

exec "$@"
