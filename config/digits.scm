(define hello-world
	(lambda ()
		(begin
			(= t 9) ; <digit 10>
			(= t a) ; <digit 16>
			(= t b) ; <digit 16>
			(= t c) ; <digit 16>
			(= t d) ; <digit 16>
			(= t e) ; <digit 16>
			(= t f) ; <digit 16>
			(write 'Hello-World)
			(newline)
			(hello-world))))
