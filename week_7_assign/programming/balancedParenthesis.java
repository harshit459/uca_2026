import java.util.*;

public class balancedParenthesis {
	
	public static boolean isBalanced(String str) {

		Stack<Character> stack = new Stack<>();

		for(char c: str.toCharArray()) {
		
			if( c == '(' || c == '{' || c == '[' )
				stack.push(c);

			else {
			
				if(stack.isEmpty())
					return false;
				
				char top = stack.pop();

				if((c == ')' && top != '(') ||
			 	   (c == '}' && top != '{') ||
			  	   (c == ']' && top != '['))
					return false;

			}

		}

		return stack.isEmpty();

	}
	
	public static void main(String[] args){
		
		String str = "[()]{}{()()}";

		boolean result = isBalanced(str);

		System.out.println(result);

	}

}
