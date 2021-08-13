#!/usr/bin/node
/*
export NODE_PATH=/usr/lib/node_modules
*/
const request = require('request');
const baseURL = 'https://swapi-api.hbtn.io/api/films/'.concat(process.argv[2]);

request(baseURL, async function (error, response, body) {
  if (error) {
    console.log(error);
    return;
  }
  const characters = JSON.parse(body).characters;

  for (let i = 0; i < characters.length; i++) {
    await new Promise(function (resolve, reject) {
      request(characters[i], function (err, res, bod) {
        if (err) {
          console.log(err);
          reject(err);
        } else {
          console.log(JSON.parse(bod).name);
          resolve();
        }
      });
    });
  }
});
