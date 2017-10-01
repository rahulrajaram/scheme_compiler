expressions = File.readlines("./expression").map(&:strip).shuffle.take(50)
sequences = File.readlines("./sequence").map(&:strip).shuffle.take(50)

case_clauses = []

expressions.each do |expression|
	sequences.each do |sequence|
		case_clauses << "(#{expression} #{sequence})"
		case_clauses << "(#{expression})"
		case_clauses << "(#{expression} => #{expression})"
	end
end

150.times do
	case_clauses.shuffle!
end

puts case_clauses.take(50)
