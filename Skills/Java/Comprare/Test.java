import java.util.*;


public class Test {
    public static void main(String[] args) {
        Deque<Integer> stackIn = new ArrayDeque<>();
        stackIn.push(8);
        stackIn.push(65);
        stackIn.push(200);
        stackIn.push(3);
        stackIn.push(15);
        System.out.println(stackIn);
        System.out.println(changeStack(stackIn));
    }
    public static Deque<Integer> changeStack(Deque<Integer> stackIn){
        Deque<Integer> stackOut = new ArrayDeque<>();
        Deque<Integer> template = new ArrayDeque<>();
        int index = 0;
        if (stackIn.size() % 2 ==1){
            index = (stackIn.size()-1)/2;
            for (int i = 0; i < index; i++) {
                template.push(stackIn.pop());
            }
            for (int i = 0; i < index; i++) {
                stackOut.push(template.pop());
            }
            stackOut.push(stackIn.pop());
            for (int i = 0; i < index; i++){
                template.push(stackIn.pop());
            }
            for (int i = 0; i < index; i++) {
                stackOut.push(template.pop());
            }
            return stackOut;
        }else{
            index = stackIn.size()/2;
            for (int i = 0; i < index; i++) {
                template.push(stackIn.pop());
            }
            for (int i = 0; i < index; i++) {
                stackOut.push(template.pop());
            }
            for (int i = 0; i < index; i++) {
                template.push(stackIn.pop());
            }
            for (int i = 0; i < index; i++) {
                stackOut.push(template.pop());
            }
            return stackOut;
        }
    }
}
