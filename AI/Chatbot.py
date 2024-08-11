def chatbot():
    print("Jarvis: Hello! I'm Jarvis, your friendly chatbot. How can I assist you today?")
    
    # Dictionary to store responses
    responses = {
        "hello": "Hi there! How can I assist you?",
        "hi": "Hi there! How can I assist you?",
        "how are you": "I'm Jarvis, and I'm always here to help! How about you?",
        "what is your name": "I am Jarvis, your virtual assistant. What's your name?",
        "weather": "I can't check the weather, but I hope it's pleasant wherever you are!",
        "hobby": "I enjoy assisting users like you! Do you have any hobbies?",
        "favorite food": "I don't eat, but if I could, I'd probably enjoy a nice slice of pizza!",
        "who created you": "I was created by a developer who loves to build cool things using Python!",
        "what can you do": "I can chat with you, answer simple questions, and keep you company! What would you like to talk about?",
        "tell me a joke": "Why don't scientists trust atoms? Because they make up everything!",
        "bye": "Goodbye! Have a fantastic day!",
    }
    user_name = None
    while True:
        user_input = input("You: ").strip().lower()
        
        if user_input.startswith("my name is"):
            user_name = user_input.replace("my name is", "").strip().capitalize()
            response = f"Nice to meet you, {user_name}!"
        elif user_name and "what is my name" in user_input:
            response = f"Your name is {user_name}, if I remember correctly!"
        else:
            response = responses.get(user_input, "I'm sorry, I didn't quite catch that. Could you please rephrase?")
        
        print(f"Jarvis: {response}")
        
        if user_input == "bye":
            break
if __name__ == "__main__":
    chatbot()
