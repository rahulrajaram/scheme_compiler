expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)
variables = File.readlines("./identifier").map(&:strip).shuffle.take(20)
bodies = File.readlines("./body").map(&:strip).shuffle.take(20)

variable_definitions = []

# (define <variable> <expression>)
#100.times do
	#variable_definitions << "(define #{variables.shuffle.first} #{expressions.shuffle.first})"
#end

# (define (<variable> <variable>*) <body>)
100.times do
	times = Random.rand(2)
	variable_definitions << "(define (#{variables.shuffle.first} #{variables.shuffle.take(times).join(" ")}) #{bodies.shuffle.first})"
end
 
# (define (<variable> <variable>* . <variable>) <body>)
100.times do
	times = Random.rand(2)
	variable_definitions << "(define (#{variables.shuffle.first} #{variables.shuffle.take(times).join(" ")} . #{variables.shuffle.first}) #{bodies.shuffle.first})"
end

100.times do
	variable_definitions.shuffle!
end

puts variable_definitions.take(40)
