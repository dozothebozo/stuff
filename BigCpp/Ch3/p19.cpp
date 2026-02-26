// Flesch Readability Index
// Write a program that computes the Flesch Readability Index to gauge the
// legibility of a document without complex linguistic analysis.
//
// Rules and Specifications:
// 1) Count all words in the file. A word is defined as any sequence of characters
//    delimited by white space, whether or not it is an actual English word.
// 2) Count all syllables in each word using these simplified rules:
//    - Each group of adjacent vowels (a, e, i, o, u, y) counts as one syllable.
//      (For example, the "ea" in "real" contributes one syllable, but the
//      "e...a" in "regal" counts as two syllables).
//    - An "e" at the end of a word does NOT count as a syllable.
//    - Each word has at least one syllable, even if the previous rules result
//      in a count of 0.
// 3) Count all sentences. A sentence is ended by any of the following punctuation
//    marks: a period (.), colon (:), semicolon (;), question mark (?), or
//    exclamation mark (!).
// 4) The Flesch reading ease score is computed and rounded to the nearest integer
//    using the standard formula:
//    Index = 206.835 - 84.6 * (Syllables / Words) - 1.015 * (Words / Sentences)
//
// Background Information:
// The resulting index is a number, usually between 0 and 100, indicating how
// difficult the text is to read. For example, comics typically score around 95,
// while consumer ads score around 82.
