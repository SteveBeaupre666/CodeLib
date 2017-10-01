#pragma once

#define DEFAULT_ASSERTION_FAILED_MSG  "Assertion Failed."

#define Assert(cnd, msg)		if(cnd == false)	throw msg;
#define AssertFalse(cnd)		if(cnd == true)		throw DEFAULT_ASSERTION_FAILED_MSG;
#define AssertTrue(cnd)			if(cnd == false)	throw DEFAULT_ASSERTION_FAILED_MSG;
#define AssertEquals(a, b)		if(a != b)			throw DEFAULT_ASSERTION_FAILED_MSG;
#define AssertNotEquals(a, b)	if(a == b)			throw DEFAULT_ASSERTION_FAILED_MSG;
#define AssertSame(a, b)		if(a != b)			throw DEFAULT_ASSERTION_FAILED_MSG;
