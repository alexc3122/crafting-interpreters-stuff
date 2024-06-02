# Challenge #3 from Chapter 1

This is a basic implementation of a doubly-linked list of heap-allocated strings. 

Things to note:
* Some of my comments, particularly on setting/assigning pointers, are VERY verbose. That's an artifact of me thinking and writing out what I needed to do.
* No optimizations are done.
* Stack protections are turned-off to make it easier to read/analyze/disassemble.
* Address sanitizer is used and can be disabled by overriding CFLAGS.
