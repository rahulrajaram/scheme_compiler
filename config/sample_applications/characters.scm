(define hello-world
	(lambda ()
		(begin
			(= a \#newline)
			(= b \#c)
			(newline)
			(hello-world))))
