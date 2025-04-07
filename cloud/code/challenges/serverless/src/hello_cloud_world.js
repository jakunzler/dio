"use strict";

const hello = async (event) => {
  return {
    statusCode: 200,
    body: JSON.stringify(
      {
        message: "Hello Cloud World! My function executed successfully!",
        input: event,
      },
      null,
      2
    ),
  };
};

module.exports = {
  handler: hello
}


