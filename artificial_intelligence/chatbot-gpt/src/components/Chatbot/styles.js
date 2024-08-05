import styled from "styled-components";

export const Container = styled.div`
    
    > div {
        width: 48px;
        height: 48px;
        position: absolute;
        top: 5rem;
        left: 2rem;

        z-index: 1;

        > img {
            transform: translate(-50%, -50%);

            background: #0da37f;

            margin-right: 8px;
            width: 100%;
            height: 100%;
            border-radius: 50%;
            cursor: pointer;
        };
    };
    
    > div {
        position: absolute;
        top: 5rem;
        left: 2rem;
        .chat-window {
            color: #555;
            width: 300px;
            height: 400px;
            background-color: #fff;
            border: 1px solid #ccc;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);
            border-radius: 5px;
            margin: 10px;
        }

        .chat-header {
            display: flex;
            align-items: center;
            justify-content: space-between;

            background-color: #f1f1f1;
            padding: 10px;
            border-bottom: 1px solid #ccc;

            > .button-close {
                display: flex;
                border: none;
                background-color: transparent;
                color: ${({ theme }) => theme.COLORS.PINK};
                cursor: pointer;
                float: right;
            }
        }

        .chat-body {
            height: 300px;
            padding: 10px;
            overflow-y: auto;

            .chat {
                color: black;
                display: flex;
                flex-direction: column;
                align-items: flex-start;

                margin-bottom: 10px;
                background: ${({ theme }) => theme.COLORS.GRAY_100};
                width: 100%;
                border-radius: 9999px;

                padding: 10px;
            }

            .user {
                color: black;
                display: flex;
                flex-direction: column;
                align-items: flex-end;
                margin-bottom: 10px;

                margin-bottom: 10px;
                background: ${({ theme }) => theme.COLORS.PINK};
                width: 100%;
                border-radius: 9999px;

                padding: 10px;
            }

        }

        .chat-footer {
            padding: 10px;
            border-top: 1px solid #ccc;
            
            > form input {
                color: black;
                width: 100%;

                padding: 5px;

                border-radius: 5px;
            }
        }
    }
`;