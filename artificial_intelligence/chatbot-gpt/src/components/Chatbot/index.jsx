import { useEffect, useRef, useState } from "react";

import { Container } from "./styles";

import { FiX } from "react-icons/fi";

// Images

import Imagebot from "../../assets/chatGPT.svg";

// Components

import { ChatMessage } from "../ChatMessage";

// Services

import { makeRequest } from "../../services/api";


export function Chatbot() {
    
    const chatbotRef = useRef(null);
    const [isChatOpen, setIsChatOpen] = useState(false);
    const [input, setInput] = useState("");
    const [chatlog, setChatlog] = useState([{
      user:"gpt",
      message:"Como posso te ajudar hoje?"
    }]);
  
    useEffect(() => {
        if (chatbotRef.current) {
            dragElement(chatbotRef.current);
        }
    }, []);

    function dragElement(element) {
        let pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;

        function dragMouseDown(e) {
            e = e || window.event;
            e.preventDefault();
            pos3 = e.clientX;
            pos4 = e.clientY;
            document.onmouseup = closeDragElement;
            document.onmousemove = elementDrag;
        }

        function elementDrag(e) {
            e = e || window.event;
            e.preventDefault();
            pos1 = pos3 - e.clientX;
            pos2 = pos4 - e.clientY;
            pos3 = e.clientX;
            pos4 = e.clientY;
            element.style.top = `${element.offsetTop - pos2}px`;
            element.style.left = `${element.offsetLeft - pos1}px`;
            element.nextSibling.style.top = `${element.offsetTop - pos2}px`;
            element.nextSibling.style.left = `${element.offsetLeft - pos1}px`;
        }

        function closeDragElement() {
            document.onmouseup = null;
            document.onmousemove = null;
        }

        element ? element.onmousedown = dragMouseDown : null;
    }

    function handleChatOpen() {
        setIsChatOpen(true);
        dragElement();
    }

    function handleChatClose() {
        setIsChatOpen(false);
    };

    async function handleSubmit(e) {
      e.preventDefault();
  
      let response = await makeRequest({prompt: input});
  
      response = response.data.split('\n').map(line => 
        <p>{line}</p>)
  
      setChatlog([...chatlog, {
        user: "user",
        message: `${input}`
      },
      {
        user:"gpt",
        message:response
      }]);
  
      setInput("");
    };
  
    return (
        <Container>
            <div ref={chatbotRef} onClick={handleChatOpen}>
                    <img src={Imagebot} alt="Imagem de um robô simpático" />
            </div>
            <div>
                {isChatOpen && (
                    <div className="chat-window">
                        <div className="chat-header">
                            Conversa atual
                            <button
                                type="button"
                                onClick={handleChatClose}
                                className={'button-close'}
                            >
                                <FiX size={24} />
                            </button>  
                        </div>
                        <div className="chat-body">
                            <div className='chat-log'>
                                {chatlog.map((message, index) => (
                                    <ChatMessage key={index} message={message}/>
                                ))}
                            </div>

                        </div>
                        <div className="chat-footer">
                            <form onSubmit={handleSubmit}>
                                <input
                                    type="text"
                                    rows = '1'
                                    className = 'chat-input-textarea'
                                    value={input}
                                    onChange={e => setInput(e.target.value)}
                                    placeholder="Digite sua mensagem..."
                                />
                            </form>
                        </div>
                    </div>
                )}
            </div>
        </Container>
    )
}