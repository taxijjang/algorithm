import spacy

nlp = spacy.load("en_core_web_sm")


def anonymize_text(sentences: str):
    doc = nlp(sentences)
    persons = [ent.text for ent in doc.ents if ent.label_ == 'PERSON']

    for person in persons:
        alphabet_X = "X" * len(person)
        sentences = sentences.replace(person, alphabet_X)
    return sentences


if __name__ == "__main__":
    sentences1 = "John is old"
    sentences2 = "Mark ate an apple Oh John"
    print(anonymize_text(sentences2))
