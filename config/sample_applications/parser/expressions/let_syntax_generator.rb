syntax_bindings = File.readlines("./syntax_binding").map(&:strip).shuffle
expressions = File.readlines("./expression").map(&:strip).shuffle

let_syntax = []

100.times do
	r = Random.rand(2)
	sb = syntax_bindings.shuffle.take(r).join(' ')
	r = Random.rand(1) + 1
	exp = expressions.shuffle.take(r).join(' ')
	let_syntax << "(let-syntax (#{sb}) #{exp})"
end

100.times do
	let_syntax.shuffle!
end

puts let_syntax.take(10)
