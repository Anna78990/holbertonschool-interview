#!/usr/bin/node

const request = require('request');

function characterLoop (character, i) {
  for (; i < character.length; i++) {
    request(character[i], function (err, res, body) {
      if (err) console.log(err);
      else console.log(JSON.parse(body).name);
    });
  }
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  function (err, res, body) {
    if (err) console.log(err);
    else {
      const charters = JSON.parse(body).characters;
      characterLoop(charters, 0);
    }
  });
