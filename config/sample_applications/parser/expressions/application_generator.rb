expressions = File.readlines("./expression").map(&:strip).shuffle

applications = []

100.times do
	r = Random.rand(2) + 1
	expressions_ = expressions.shuffle.take(r).join(' ')
	applications << "(#{expressions_})"
end

100.times do
	applications.shuffle!
end

puts applications.take(50)
