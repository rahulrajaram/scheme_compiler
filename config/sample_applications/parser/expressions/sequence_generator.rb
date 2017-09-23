expressions = File.readlines("./expression").map(&:strip).shuffle

sequences = []

100.times do
	r = Random.rand(2) + 1
	expressions_ = expressions.shuffle.take(r).join(' ')
	sequences << "(#{expressions_})"
end

100.times do
	sequences.shuffle!
end

puts sequences.take(50)
