cond_clauses = File.readlines("./cond_clause").map(&:strip).shuffle.take(20)
case_clause = File.readlines("./case_clause").map(&:strip).shuffle.take(20)
expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)
sequences = File.readlines("./sequence").map(&:strip).shuffle.take(20)
binding_specs = File.readlines("./binding_spec").map(&:strip).shuffle.take(20)
iteration_specs = File.readlines("./iteration_spec").map(&:strip).shuffle.take(20)
variables = File.readlines("./identifier").map(&:strip).shuffle.take(20)
bodies = File.readlines("./body").map(&:strip).shuffle.take(20)

derived_expressions = []

# (cond <cond clause>+)
100.times do
	times = Random.rand(1) + 1
	derived_expressions << "(cond #{cond_clauses.shuffle.take(times).join(" ")})"
end

# (cond <cond clause>* (else <sequence>))
100.times do
	times = Random.rand(1) + 1
	derived_expressions << "(cond #{cond_clauses.shuffle.take(times).join(" ")} (else #{sequences.shuffle.first}))"
end
 
# (case <expression> <case clause>+)
100.times do
	times = Random.rand(1) + 1
	derived_expressions << "(case #{expressions.shuffle.first} #{case_clause.shuffle.take(times).join(" ")})"
end

# (case <expression> <case clause>* (else <sequence>))
100.times do
	times = Random.rand(2)
	derived_expressions << "(case #{expressions.shuffle.first} #{case_clause.shuffle.take(times).join(" ")} (else #{sequences.shuffle.first}))"
end

# (and <test>*)
100.times do
	times = Random.rand(2)
	derived_expressions << "(and #{expressions.shuffle.take(times).join(" ")})"
end

# (or <test>*)
100.times do
	times = Random.rand(2)
	derived_expressions << "(or #{expressions.shuffle.take(times).join(" ")})"
end
 
# (let (<binding spec>*) <body>)
100.times do
	times = Random.rand(2)
	derived_expressions << "(let (#{binding_specs.shuffle.take(times).join(" ")}) #{bodies.shuffle.first})"
end

# (let variable (<binding spec>*) <body>)
100.times do
	times = Random.rand(2)
	derived_expressions << "(let #{variables.shuffle.first} (#{binding_specs.shuffle.take(times).join(" ")}) #{bodies.shuffle.first})"
end

# (let* variable (<binding spec>*) <body>)
100.times do
	times = Random.rand(2)
	derived_expressions << "(let* #{variables.shuffle.first} (#{binding_specs.shuffle.take(times).join(" ")}) #{bodies.shuffle.first})"
end


# (letrec variable (<binding spec>*) <body>)
100.times do
	times = Random.rand(2)
	derived_expressions << "(letrec #{variables.shuffle.first} (#{binding_specs.shuffle.take(times).join(" ")}) #{bodies.shuffle.first})"
end

# (begin <sequence>)
100.times do
	derived_expressions << "(begin #{sequences.shuffle.first})"
end

# (do (<iteration spec>*)
#  		(<test> <do result>)
#     <command>*)
100.times do
	times = Random.rand(2)
	times_1 = Random.rand(1)
	times_2 = Random.rand(2)
	derived_expressions << [
		"(do (#{iteration_specs.shuffle.take(times).join(' ')})",
		 "(#{expressions.shuffle.first} #{sequences.shuffle.take(times_1)})",
		"#{expressions.shuffle.take(times_2).join(' ')}"
	].join(' ')
end

# (delay <expression>)
100.times do
	derived_expressions << "(delay #{expressions.shuffle.first})"
end

100.times do
	derived_expressions.shuffle!
end

puts derived_expressions.take(50)
