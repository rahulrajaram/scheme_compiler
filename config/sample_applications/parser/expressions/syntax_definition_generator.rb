keywords = File.readlines("./keyword").map(&:strip).shuffle
transformer_expressions = File.readlines("./transformer_expression").map(&:strip)

sb = []

keywords.each do |keyword|
	transformer_expressions.each do |te|
		sb << "(define-syntax #{keyword} #{te})"
	end
end

100.times do
	sb.shuffle!
end

puts sb.take(50)
