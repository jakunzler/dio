import styled from "styled-components";

export const Container = styled.div`

    .chat-gpt {
        background-color: ${({ theme }) => theme.COLORS.GREY_100};
    }

    .chat-user {
        background-color: ${({ theme }) => theme.COLORS.GREY_300};
    }

    > .chat-message-center {
      display: flex;
      align-items: center;
      gap: 5px;

      margin: 0 auto;

      padding: 5px 0;
    }

    > div .avatar {
    
      width: 24px;
      height: 24px;

      > img {
        width: 100%;
        height: 100%;
      }
    }

    > .message {
        padding: 0 10px;

        max-width: 100px;
    }

`;
