#!/usr/bin/env python
# -*- coding: utf-8 -*-


###############################################################################
# regular expressions (RE). 正则表达式
###############################################################################
# https://www.runoob.com/python3/python3-reg-expressions.html
import re

# action: Try to apply the pattern    at the start of the string (match),
#                                     to all of the string       (fullmatch),
#         Scan through string looking for a match to the pattern (search),
# return: returning a Match object, or None if no match was found.
m = re.match(pattern, string, flags=0)
m = re.fullmatch(pattern, string, flags=0)
m = re.search(pattern, string, flags=0)

print(m.group(1))
print(m.group(2))


# return: Return a list of all non-overlapping matches in the string.
# note:
#     If one or more capturing groups are present in the pattern, return
#     a list of groups; this will be a list of tuples if the pattern
#     has more than one group.
#
# return: Return an iterator over all non-overlapping matches in the string.
# note:
#     For each match, the iterator returns a Match object.
#
#     Empty matches are included in the result.
re.findall(pattern, string, flags=0)
re.finditer(pattern, string, flags=0)

# return: Return the string obtained by replacing the leftmost
#     non-overlapping occurrences of the pattern in string by the
#     replacement repl.  repl can be either a string or a callable;
#     if a string, backslash escapes in it are processed.  If it is
#     a callable, it's passed the Match object and must return
#     a replacement string to be used.
#
# return: Return a 2-tuple containing (new_string, number).
#     new_string is the string obtained by replacing the leftmost
#     non-overlapping occurrences of the pattern in the source
#     string by the replacement repl.  number is the number of
#     substitutions that were made. repl can be either a string or a
#     callable; if a string, backslash escapes in it are processed.
#     If it is a callable, it's passed the Match object and must
#     return a replacement string to be used.
re.sub(pattern, repl, string, count=0, flags=0)
re.subn(pattern, repl, string, count=0, flags=0)

# action: Split the source string by the occurrences of the pattern,
# return: returning a list containing the resulting substrings.
# note:
#     If capturing parentheses are used in pattern, then the text of all
#     groups in the pattern are also returned as part of the resulting
#     list.  If maxsplit is nonzero, at most maxsplit splits occur,
#     and the remainder of the string is returned as the final element
#     of the list.
re.split(pattern, string, maxsplit=0, flags=0)


# Each function other than purge and escape can take an optional 'flags' argument
# consisting of one or more of the following module constants, joined by "|".
# A, L, and U are mutually exclusive.
#     re.I  IGNORECASE  Perform case-insensitive matching.
#     re.S  DOTALL      "." matches any character at all, including the newline.
#     re.M  MULTILINE   "^" matches the beginning of lines (after a newline)
#                       as well as the string.
#                       "$" matches the end of lines (before a newline) as well
#                       as the end of the string.
#
#     re.X  VERBOSE     Ignore whitespace and comments for nicer looking RE's.
#     re.L  LOCALE      Make \w, \W, \b, \B, dependent on the current locale.
#     re.U  UNICODE     For compatibility only. Ignored for string patterns (it
#                       is the default), and forbidden for bytes patterns.
#     re.A  ASCII       For string patterns, make \w, \W, \b, \B, \d, \D
#                       match the corresponding ASCII character categories
#                       (rather than the whole Unicode categories, which is the
#                       default).
#                       For bytes patterns, this flag is the only available
#                       behaviour and needn't be specified.

