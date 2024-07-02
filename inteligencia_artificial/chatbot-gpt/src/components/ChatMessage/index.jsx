import React, { useState } from "react";

import { Container } from "./styles";

import emptyImage from "../../assets/empty-profile.png";

import gptImage from "../../assets/chatGPT.png";

export function ChatMessage({ message }) {
    
    const avatarUrl = emptyImage;
    const [avatar, setAvatar] = useState(avatarUrl);

    return(
        <Container 
            className={
                `chat-${message.user}`}
        >

            <div className="chat-message-center">
                <div className={
                    `avatar chat-${message.user}}`}
                >
                    {message.user === 'gpt' ? <img src={gptImage} /> : <img src={avatar} />}

                </div>

                <div className="message">
                    {message.message}
                </div>
            </div>
        </Container>
    );
};