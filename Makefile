prepare:
	LC_CTYPE=C tr -dc 'A-Z' </dev/urandom | dd bs=1 count=1048576 of=test.txt

build-cpp:
	cd cpp; mkdir build; cd build && cmake .. && make

test-cpp:
	[ -d "cpp/build" ] && cd cpp/build && ./main || echo "####################\nRun build-cpp first.\n####################"

debug-cpp:
	[ -d "cpp/build" ] && cd cpp/build && ./debug || echo "####################\nRun build-cpp first.\n####################"
