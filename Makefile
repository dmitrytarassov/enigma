.PHONY: prepare

prepare:
	LC_CTYPE=C tr -dc 'A-Z' </dev/urandom | dd bs=1 count=1048576 of=test.txt