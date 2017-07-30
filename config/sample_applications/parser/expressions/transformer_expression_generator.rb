identifiers = File.readlines("./identifier").map(&:strip).take(10)
syntax_rule = File.readlines("./syntax_rule").map(&:strip).take(10)

transformer_expression = ["(syntax-rules ())"]

10.times do
	[1, 2].each do |i|
		ids = identifiers.shuffle.take(i)
		sr = syntax_rule.shuffle.take(i)
		transformer_expression << "(syntax-rules (#{ids.join(' ')}) #{sr.join(' ')})"
	end
end
puts transformer_expression
