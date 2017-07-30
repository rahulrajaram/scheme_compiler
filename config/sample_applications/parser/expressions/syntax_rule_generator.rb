patterns = File.readlines("./pattern").map(&:strip)
templates = File.readlines("./template").map(&:strip)

syntax_rules = []
patterns.each do |pattern|
	templates.each do |template|
		syntax_rules << "(#{pattern} #{template})"
	end
end
500.times do
	syntax_rules.shuffle!
end

puts syntax_rules.take(500)
