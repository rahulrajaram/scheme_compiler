variables = File.readlines("./identifier").map(&:strip).shuffle.take(20)
expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)

binding_specs = []

variables.each do |variable|
	expressions.each do |expression|
		binding_specs << "(#{variable} #{expression})"
	end
end

100.times do
	binding_specs.shuffle!
end

puts binding_specs.take(50)
