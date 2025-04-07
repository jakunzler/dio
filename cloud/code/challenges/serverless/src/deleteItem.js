'use strict';

const AWS = require("aws-sdk")

const deleteItem = async (event) => {

  const { id } = event.pathParameters;

  const dynamodb = new AWS.DynamoDB.DocumentClient();

  await dynamodb.delete({
    TableName: "test-db",
    Key: {
      test_id: id
    }
  }).promise()

  return {
    statusCode: 200,
    body: JSON.stringify({}),
  };
};

module.exports = {
  handler: deleteItem
}