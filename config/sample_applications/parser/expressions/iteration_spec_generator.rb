variables = File.readlines("./identifier").map(&:strip).shuffle.take(20)
expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)

iteration_specs = []

variables.each do |variable|
	expressions.each do |expression|
		expressions.each do |expression_1|
			iteration_specs << "(#{variable} #{expression} #{expression_1})"
		end
		iteration_specs << "(#{variable} #{expression})"
	end
end

100.times do
	iteration_specs.shuffle!
end

puts iteration_specs.take(50)
