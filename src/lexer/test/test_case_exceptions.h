#ifndef ATRIUM_TEST_CASE_EXCEPTIONS_H
#define ATRIUM_TEST_CASE_EXCEPTIONS_H

#include <exception>
#include <iostream>

namespace Atrium {

	class AtriumTestBaseException : public std::exception {
	protected:
		std::string error_message;
	public:
		virtual const char* what() const noexcept {
			return error_message.c_str();
		}

		virtual const char* what() noexcept {
			return error_message.c_str();
		}
	};

	class SourceFileNotFoundException : public AtriumTestBaseException {
	public:
		SourceFileNotFoundException(
			const std::string& source_file_name
		) {
			error_message =
			 	"error: SourceFileNotFoundException:: Source file "
			 		+ source_file_name
					+ " is not present.";
		}
	};

	class VectorsNotEqualException : public AtriumTestBaseException {
	public:
		VectorsNotEqualException(
			const int differ_at
		) {
			error_message =
				"error: VectorsNotEqualException:: 'expected' and 'actual' vectors differ at index "
					+ std::to_string(differ_at)
				 	+ ".";
		}
	};

	class VectorsNotOfEqualSizeException : public AtriumTestBaseException {
	public:
		VectorsNotOfEqualSizeException(
			std::size_t expected_vector_size,
			std::size_t actual_vector_size
		) {
			error_message =
				"error: VectorNotOfEqualSizeException:: 'expected' vector size was "
					+ std::to_string(expected_vector_size)
				 	+	" whereas 'actual' vector size was "
					+ std::to_string(actual_vector_size)
				 	+ ".";
		}
	};
}

#endif
