; this is a comment in scheme
(define hello-world
	(lambda ()
		(begin
			#| This is a comment as well.
			|#
			(write 'Hello-World) ; This is yet another comment
			(newline)
			(hello-world))))
