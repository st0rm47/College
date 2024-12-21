from collections import defaultdict

def naive_bayes_predict(data, condition, feature_index, target_index):
    # Initialize dictionaries to store counts
    feature_target_counts = defaultdict(lambda: defaultdict(int))
    target_counts = defaultdict(int)

    # Count occurrences in the dataset
    for row in data:
        feature = row[feature_index]
        target = row[target_index]
        feature_target_counts[feature][target] += 1
        target_counts[target] += 1

    # Calculate prior probabilities
    total_count = len(data)
    priors = {target: count / total_count for target, count in target_counts.items()}

    # Calculate likelihoods for the given condition
    likelihoods = {}
    for target in target_counts:
        # Count how many times the condition appears for each target class
        likelihoods[target] = (
            feature_target_counts[condition][target] / target_counts[target]
            if target_counts[target] > 0 else 0
        )

    # Calculate posterior probabilities
    posteriors = {
        target: priors[target] * likelihoods[target] for target in target_counts
    }

    # Normalize posterior probabilities
    total_posterior = sum(posteriors.values())
    normalized_posteriors = {
        target: posteriors[target] / total_posterior if total_posterior > 0 else 0
        for target in posteriors
    }

    # Print detailed probabilities
    print("\n--- Detailed Probability Values ---")
    for target in target_counts:
        print(f"P({target}): {priors[target]}")
        print(f"P(Condition | {target}): {likelihoods[target]}")
        print(f"P({target} | Condition): {normalized_posteriors[target]}")
    print("\n----------------------------------")

    # Return the class with the highest posterior probability
    return max(normalized_posteriors, key=normalized_posteriors.get)


def main():
    # Example dataset: Email classification (Spam or Not Spam)
    email_data = [
        ('Free money', 'Spam'),
        ('Win a lottery now', 'Spam'),
        ('Claim your prize', 'Spam'),
        ('Exclusive offer just for you', 'Spam'),
        ('Meeting at 3 PM', 'Not Spam'),
        ('Project deadline reminder', 'Not Spam'),
        ('Team lunch invitation', 'Not Spam'),
        ('Can we reschedule?', 'Not Spam'),
        ('Congratulations! You won', 'Spam'),
        ('Urgent: Update your account', 'Spam')
    ]

    # Ask user for input
    user_email = input("Enter the email subject line: ")

    # Predict outcome
    outcome = naive_bayes_predict(email_data, user_email, feature_index=0, target_index=1)
    print(f"Prediction: Email is {outcome}")
    
if __name__ == "__main__":
    main()
    
    