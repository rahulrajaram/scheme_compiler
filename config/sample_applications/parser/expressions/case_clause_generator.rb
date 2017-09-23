datums = File.readlines("./datum").map(&:strip).shuffle
sequence = File.readlines("./sequence").map(&:strip).shuffle

case_clause = []

100.times do
	r = Random.rand(2)
	d = datums.shuffle.take(r).join(' ')
	r = Random.rand(1) + 1
	s = sequence.shuffle.take(r).join(' ')
	case_clause << "((#{d}) #{s})"
end

100.times do
	case_clause.shuffle!
end

puts case_clause.take(50)
