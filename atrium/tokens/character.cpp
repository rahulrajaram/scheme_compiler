#include "token.h"

namespace Atrium {
	Token::non_printing_characters_map = {
			{"altmode", 				"ESC"},
			{"acknowledge",			"ACK"},
			{"backnext", 				"US"},
			{"backspace", 			"BS"},
			{"bell", 						"BEL"},
			{"call", 						"SUB"},
			{"can", 						"CAN"},
			{"crreturn",				"CR"},
			{"devcont1",				"DC1"},
			{"devcont2",				"DC2"},
			{"devcont3",				"DC3"},
			{"devcont4",				"DC4"},
			{"datalinkesc",			"DLE"},
			{"endoftext", 			"ETX"},
			{"endoftrans", 			"EOT"},
			{"endofmedium", 		"EM"},
			{"enquiry", 				"ENQ"},
			{"endoftransblk",		"ETB"},
			{"fileseparator",		"FS"},
			{"groupseparator", 	"GS"},
			{"horitab",					"TAB"},
			{"linefeed", 				"LF"},
			{"newline", 				"LF"},
			{"negativeack",			"NAK"},
			{"null", 						"NUL"},
			{"formfeed",				"FF"},
			{"recordseparator", "RS"},
			{"shiftin", 				"SI"},
			{"space", 					" "},
			{"startofheading", 	"SOH"},
			{"shiftout", 				"SO"},
			{"substitute", 			"SUB"},
			{"synidle", 				"SYN"},
			{"verticaltab",	 		"VT"}
		};

	bool Token::is_non_printing_char() {
		if (token.length() < 4) {
			return false;
		}

		if (starts_with_prefix("#\\")) {
			return(
				non_printing_characters_map.find([token.substr(3)])
				!= non_printing_characters_map.end()
			);
		}	
	}
	bool Token::is_non_printing_char() {
		if (token.length() != 3) {
			return false;
		}

		if (
			starts_with_prefix("#\\")
			&& token[2] >= 33
		 	&& token[2] <= 128
		) {
			return(
				non_printing_characters_map.find([token.substr(3)])
				!= non_printing_characters_map.end()
			);
		}	
	}

	bool Token::is_character() {
		if (is_non_printing_char()) {
			return true;
		}

		if (is_printing_char()) {
			return true;
		}

		/*
		 * TODO: Handle bucky bits
		 * */
		return false;
	}
}
