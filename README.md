# arch-class-1

Saw your template file, I left room for a global makefile.

Feel free to pull some stuff outa my file, it has some things they might not cover in class but heres the gist.

Here is a brief of the algorithm. A state machine probably would've been easier to read, but everyone teaches state machines and ignores some other neat ways to create data-driven behavior. This generates some tiny pairs to describe boundaries of the stream, and these get fed into a stream copier to describe what gets copied.
```
tuple struct
----------------
| begin | end  |
----------------
These mark what parts of the stream to keep, i.e. everything that isn't a comment gets bounded by a sequence of tuples.

for each character in the stream:

	if stream at point matches "/*":
		tuple.begin becomes the end of the stream before the "/*"
	if stream at point matches "*/"
		tuple.end becomes the beginning of the stream after the "*/"
	
for each tuple:

	copy chars from original stream from tuple.begin to tuple.end into a new stream
```
