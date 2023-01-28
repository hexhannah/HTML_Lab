//Function Name: isValid
//Return Type: boolean
//Parameters: none
//Purpose: Check is each opening tag in a HTML file has a matching
//closing tag.
bool HTMLChecker::isValid() {
    stack<string> vStack;  //create stack that will store the open/close tags

    while (!html_elements.empty()) {   //while the html queue isnt empty
        string current = html_elements.front();   //current is front of queue

        if(self_closing_tags.find(current)==self_closing_tags.end()) {   //check that is not selfclosing

            string firstCharacter = current.substr(0, 1);     //string of the 1st character of current
            string secondChar = current.substr(1, 1);         //string of the 2nd character of current

            if (firstCharacter == "<" && secondChar == "/") {         //if a closing tag
                string bodyOfCurrent = current.substr(2);        // everything after </

                if(!vStack.empty()) {                                 //stack isnt empty, opening tag in there
                    string top = vStack.top();                        //top of Stack
                    string bodyOfTop = top.substr(1);            //top of Stack after the <

                    if (bodyOfTop == bodyOfCurrent) {                 //if closing tag match open tag remove open tag
                        vStack.pop();
                    }
                    else return false;                                //doesnt match so not valid
                }
                else return false;                                    //if stack isnt empty its false
            }
            else if (firstCharacter == "<") {                         // if current is opening tag push
                    vStack.push(current);
            }
        }
        html_elements.pop();            //regardless remove element from queue
    }
    if(!vStack.empty()) return false;  //if each tag wasnt matched
    return true;                       // each tag was matched
}
