package Unitone;

// Custom Exception with Message
public class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }

    public static void Exception(int age) throws CustomException{
        if(age<25){
            throw new CustomException("Age is not valid");
        }else{
            System.out.println("Age is Valid");
        }
    }

    public static void main(String[] args) {
        try {
            Exception(20);
        }
        catch(CustomException ex){
            System.out.println(ex.getMessage());
        }
    }
}


