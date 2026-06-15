# 2082

## Question 2: Write a JavaFX application that creates a ChoiceBox with a list of colors. Display a label that changes its text based on the selected color from the ChoiceBox.

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ColorChoiceBoxApp extends Application {

    @Override
    public void start(Stage stage) {
        VBox vbox = new VBox(10);

        // Create a Label to display the selected color
        Label selectedColorLabel = new Label("Select a color from the ChoiceBox");

        // Create a ChoiceBox with a list of colors
        ChoiceBox<String> colorChoiceBox = new ChoiceBox<>();

        colorChoiceBox.getItems().addAll("Red", "Green", "Blue", "Yellow", "Purple");


        // Add an event listener to the ChoiceBox to update the Label when a color is selected
        colorChoiceBox.setOnAction(e -> {
            String selectedColor = colorChoiceBox.getValue();
            selectedColorLabel.setText("Selected Color: " + selectedColor);
        });

        // Create a VBox layout and add the ChoiceBox and Label to it
        vbox.getChildren().addAll(colorChoiceBox, selectedColorLabel);

        // Set up the Scene and Stage
        Scene scene = new Scene(vbox, 300, 200);
        stage.setTitle("Color ChoiceBox Example");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

# Model 2

## Question 11:  Write a JavaFX program to create a form to read two numbers and display their sum on button click.
**Example JavaFX program**
```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class SumCalculator extends Application {
    @Override
    public void start(Stage stage) {
        VBox vbox= new VBox(10);

        // Create UI components
        Label num1label = new Label("Enter 1st number");
        TextField num1Field = new TextField();

        Label num2label = new Label("Enter 2nd number");
        TextField num2Field = new TextField();

        Button calculateButton = new Button("Calculate Sum");
        Label resultLabel = new Label();

        // Set up layout
        vbox.getChildren().addAll(num1label, num1Field, num2label, num2Field, calculateButton, resultLabel);

        // Set button action
        calculateButton.setOnAction(e -> {
            try {
                int num1 =   Integer.parseInt(num1Field.getText());
                int num2 =   Integer.parseInt(num2Field.getText());
                int sum = num1 + num2;
                resultLabel.setText("Sum: " + sum);
            } catch (Exception ex) {
                resultLabel.setText("Please enter valid numbers.");
            }
        });

        // Set up the scene and stage
        Scene scene = new Scene(vbox, 300, 200);
        stage.setTitle("Sum Calculator");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
```

---

