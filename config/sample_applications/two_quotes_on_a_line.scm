(let ([f (let ([x 'sam])
	(lambda (y z) (list x y z)))])
	  (let ([x 'not-sam])
	    (f 'i 'am)))
