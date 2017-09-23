variable_definitions = File.readlines("./variable_definition").map(&:strip).shuffle.take(20)
syntax_definitions = File.readlines("./syntax_definition").map(&:strip).shuffle.take(20)
derived_expressions = File.readlines("./variable_definition").map(&:strip).shuffle.take(20)
syntax_bindings = File.readlines("./syntax_binding").map(&:strip).shuffle.take(20)
definitions = File.readlines("./definition").map(&:strip).shuffle.take(20)

definitions = variable_definitions + syntax_definitions + derived_expressions

# (begin <definition>*)
50.times do
	times = Random.rand(2)
	definitions << "(begin #{definitions.shuffle.take(times).join(" ")})"
end

# (let-syntax (<syntax binding>*) <definition>*)
50.times do
	times = Random.rand(2)
	times_1 = Random.rand(2)
	definitions << "(let-syntax (#{syntax_bindings.shuffle.take(times).join(" ")}) #{definitions.shuffle.take(times_1).join(" ")})"
end

# (letrec-syntax (<syntax binding>*) <definition>*)
50.times do
	times = Random.rand(2)
	times_1 = Random.rand(2)
	definitions << "(letrec-syntax (#{syntax_bindings.shuffle.take(times).join(" ")}) #{definitions.shuffle.take(times_1).join(" ")})"
end
 
100.times do
	definitions.shuffle!
end

puts definitions.take(50)
