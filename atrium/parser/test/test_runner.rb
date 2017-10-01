if ARGV[0] == "-c"
	ret = system(`make clean`)

	unless ret
		raise("'make clean' failed")
	end

end

ret = system('make')
unless ret
	raise("'make' failed")
end

tests = Dir.entries("bin")
skip = ['helper', ".o"]

total = 0
successes = 0
failures = 0

tests.each do |test|
	next if skip.any?{ |s| !test.include?("test_") || test.include?(s) }

	ret = system("./bin/#{test}")

	if ret
		successes = successes + 1
		puts "\033[1;32m#{test}\033[0m"
	else
		failures = failures + 1
		puts "\033[1;31m#{test}\033[0m"
	end

	total = total + 1
end

puts ""
puts "\033[1;33m***************************** Summary *************************************\033[0m"
puts "\t\033[1;33mTotal: #{total}\033[0m"
if successes > 0
	puts "\t\033[1;32mSuccesses: #{successes}\033[0m"
end

if failures > 0
	puts "\t\033[1;31mFailures: #{failures}\033[0m"
end
puts "\033[1;33m***************************************************************************\033[0m"
