"use strict";

const AWS = require("aws-sdk")

const updateItem = async (event) => {

  const { itemName, itemStatus, qtd, color } = JSON.parse(event.body);
  const { id } = event.pathParameters
  const createdAt = new Date().toISOString();

  const dynamodb = new AWS.DynamoDB.DocumentClient();

  await dynamodb.update({
    TableName: "test-db",
    Key: { test_id: id },
    UpdateExpression: 'set itemStatus = :itemStatus, itemName = :itemName, qtd = :qtd, updatedAt = :updatedAt, color = :color',
    ExpressionAttributeValues: {
      ':itemName': itemName,
      ':itemStatus': itemStatus,
      ':qtd': qtd,
      ':updatedAt': createdAt,
      ':color': color
    },
    ReturnValues: "ALL_NEW"
  }).promise()

  return {
    statusCode: 200,
    body: JSON.stringify(
      { msg: 'Item updated' }
    ),
  };
};

module.exports = {
  handler: updateItem
}


