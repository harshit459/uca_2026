import java.util.*;

public class postfixExpression {

	public static int evaluate(String str) {

		Stack<Integer> stack = new Stack<>();
	
		for(String s: str.split(" ")) {
		
			if(s.equals("+") || 
			   s.equals("-") || 
			   s.equals("*") || 
			   s.equals("/")) {
			   
				int b = stack.pop();
				int a = stack.pop();

				switch(s) {
				
					case "+":
						stack.push(a+b);
						break;

					case "-":
						stack.push(a-b);
						break;

					case "*":
						stack.push(a*b);
						break;

					case "/":
						stack.push(a/b);
						break;
				
				}
			   
			   }
			else {
			
				stack.push(Integer.parseInt(s));
			
			}

		}

		return stack.pop();

	}

	public static void main(String[] args) {
	
		String str = "2 3 1 * + 9 -";

		int result = evaluate(str);

		System.out.println(result);
	
	}

}
