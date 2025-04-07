"use strict";

const { v4 } = require("uuid");
const AWS = require("aws-sdk")

const insertItem = async (event) => {

  const { item } = JSON.parse(event.body);
  const createdAt = new Date().toISOString();
  const id = v4()

  const dynamodb = new AWS.DynamoDB.DocumentClient();

  const newItem = {
    test_id: id,
    color: "standard",
    isActive: true,
    itemName: item.itemName,
    qtd: item.qtd,
    createdAt,
    updatedAt: createdAt,
    itemStatus: "in stock"
  }

  await dynamodb.put({
    TableName: "test-db",
    Item: newItem
  }).promise()

  return {
    statusCode: 200,
    body: JSON.stringify(newItem),
  };
};


module.exports = {
  handler: insertItem
}


