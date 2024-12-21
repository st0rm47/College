class ExpertSystem:
    def __init__(self):
        self.knowledge_base = {
            'Preferences': ['Outdoor Activities', 'Relaxation', 'Adrenaline Rush', 'Team Sports', 'Solo Activities', 'Creative Pursuits'],
            'Suggestions': ['Hiking', 'Yoga', 'Skydiving', 'Basketball', 'Reading', 'Painting'],
            'Hiking': ['Outdoor Activities', 'Adrenaline Rush'],
            'Yoga': ['Relaxation', 'Solo Activities'],
            'Skydiving': ['Adrenaline Rush', 'Solo Activities'],
            'Basketball': ['Team Sports', 'Outdoor Activities'],
            'Reading': ['Relaxation', 'Solo Activities'],
            'Painting': ['Creative Pursuits', 'Relaxation'],
        }
        self.preferences = []

    def ask_question(self):
        for category in self.knowledge_base['Preferences']:
            answer = input(f"Do you enjoy {category.lower()}? (yes/no): ").strip().lower()
            if answer in ['yes', 'y']:
                self.preferences.append(category)

    def suggest(self):
        print("\nGathering your preferences...\n")
        self.ask_question()
        activity_scores = {}

        for activity in self.knowledge_base['Suggestions']:
            activity_scores[activity] = 0
            for preference in self.knowledge_base.get(activity, []):
                if preference in self.preferences:
                    activity_scores[activity] += 1

        max_score = max(activity_scores.values(), default=0)
        best_matches = [activity for activity, score in activity_scores.items() if score == max_score and score > 0]

        if best_matches:
            print("\nBased on your preferences, we suggest the following activities:")
            for match in best_matches:
                print(f"-> {match}")
        else:
            print("\nWe couldn't find any activities matching your preferences.")
            print("Try exploring new interests and activities!")

if __name__ == "__main__":
    print("Welcome to the Activity Suggestion Expert System!")
    expert_system = ExpertSystem()
    expert_system.suggest()
