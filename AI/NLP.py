import nltk
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

# Download necessary resources from NLTK
nltk.download('punkt')
nltk.download('stopwords')

# Take input from the user
text = input("\n Enter the text for NLP processing: ")

# 1. Sentence Tokenization
sentences = sent_tokenize(text)
print("Sentence Tokenization:")
print(sentences)
print()

# 2. Word Tokenization
words = word_tokenize(text)
print("Word Tokenization:")
print(words)
print()

# 3. Removing Stopwords
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]
print("Filtered Words (Stopwords removed):")
print(filtered_words)
print()

# 4. Stemming (Reducing words to their base form)
stemmer = PorterStemmer()
stemmed_words = [stemmer.stem(word) for word in filtered_words]
print("Stemmed Words:")
print(stemmed_words)
