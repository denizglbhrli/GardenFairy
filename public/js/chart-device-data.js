/* eslint-disable max-classes-per-file */
/* eslint-disable no-restricted-globals */
/* eslint-disable no-undef */

// TODO: Deniz, update these
const chartData = {
  1: {
    datasets: [
      {
        fill: false,
        label: "Temperature",
        yAxisID: "Temperature",
        borderColor: "rgba(255, 204, 0, 1)",
        pointBoarderColor: "rgba(255, 204, 0, 1)",
        backgroundColor: "rgba(255, 204, 0, 0.4)",
        pointHoverBackgroundColor: "rgba(255, 204, 0, 1)",
        pointHoverBorderColor: "rgba(255, 204, 0, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  2: {
    datasets: [
      {
        fill: false,
        label: "Humidity",
        yAxisID: "Humidity",
        borderColor: "rgba(53, 167, 232, 1)",
        pointBoarderColor: "rgba(53, 167, 232, 1)",
        backgroundColor: "rgba(53, 167, 232, 0.4)",
        pointHoverBackgroundColor: "rgba(53, 167, 232, 1)",
        pointHoverBorderColor: "rgba(53, 167, 232, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  3: {
    datasets: [
      {
        fill: false,
        label: "pH",
        yAxisID: "pH",
        borderColor: "rgba(37, 250, 52, 1)",
        pointBoarderColor: "rgba(37, 250, 52, 1)",
        backgroundColor: "rgba(37, 250, 52, 0.4)",
        pointHoverBackgroundColor: "rgba(37, 250, 52, 1)",
        pointHoverBorderColor: "rgba(37, 250, 52, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  4: {
    datasets: [
      {
        fill: false,
        label: "Conductivity",
        yAxisID: "Conductivity",
        borderColor: "rgba(231, 3, 252, 1)",
        pointBoarderColor: "rgba(231, 3, 252, 1)",
        backgroundColor: "rgba(231, 3, 252, 0.4)",
        pointHoverBackgroundColor: "rgba(231, 3, 252, 1)",
        pointHoverBorderColor: "rgba(231, 3, 252, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  5: {
    datasets: [
      {
        fill: false,
        label: "Nitrogren",
        yAxisID: "Nitrogen",
        borderColor: "rgba(242, 59, 39, 1)",
        pointBoarderColor: "rgba(242, 59, 39, 1)",
        backgroundColor: "rgba(242, 59, 39, 0.4)",
        pointHoverBackgroundColor: "rgba(242, 59, 39, 1)",
        pointHoverBorderColor: "rgba(242, 59, 39, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  6: {
    datasets: [
      {
        fill: false,
        label: "Phosphorus",
        yAxisID: "Phosphorus",
        borderColor: "rgba(61, 26, 237, 1)",
        pointBoarderColor: "rgba(61, 26, 237, 1)",
        backgroundColor: "rgba(61, 26, 237, 0.4)",
        pointHoverBackgroundColor: "rgba(61, 26, 237, 1)",
        pointHoverBorderColor: "rgba(61, 26, 237, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  7: {
    datasets: [
      {
        fill: false,
        label: "Potassium",
        yAxisID: "Potassium",
        borderColor: "rgba(242, 178, 29, 1)",
        pointBoarderColor: "rgba(242, 178, 29, 1)",
        backgroundColor: "rgba(242, 178, 29, 0.4)",
        pointHoverBackgroundColor: "rgba(242, 178, 29, 1)",
        pointHoverBorderColor: "rgba(242, 178, 29, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  8: {
    datasets: [
      {
        fill: false,
        label: "Ambient Temperature",
        yAxisID: "Ambient Temperature",
        borderColor: "rgba(6, 87, 38, 1)",
        pointBoarderColor: "rgba(6, 87, 38, 1)",
        backgroundColor: "rgba(6, 87, 38, 0.4)",
        pointHoverBackgroundColor: "rgba(6, 87, 38, 1)",
        pointHoverBorderColor: "rgba(6, 87, 38, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
  9: {
    datasets: [
      {
        fill: false,
        label: "Light",
        yAxisID: "Light",
        borderColor: "rgba(135, 49, 189, 1)",
        pointBoarderColor: "rgba(135, 49, 189, 1)",
        backgroundColor: "rgba(135, 49, 189, 0.4)",
        pointHoverBackgroundColor: "rgba(135, 49, 189, 1)",
        pointHoverBorderColor: "rgba(135, 49, 189, 1)",
        spanGaps: true,
        data: [],
      },
    ],
  },
};

// TODO: Deniz, update these
const chartOptions = {
  1: {
    scales: {
      yAxes: [
        {
          id: "Temperature",
          type: "linear",
          scaleLabel: {
            labelString: "Temperature (ºC)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  2: {
    scales: {
      yAxes: [
        {
          id: "Humidity",
          type: "linear",
          scaleLabel: {
            labelString: "Humidity (%RH)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  3: {
    scales: {
      yAxes: [
        {
          id: "pH",
          type: "linear",
          scaleLabel: {
            labelString: "pH",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  4: {
    scales: {
      yAxes: [
        {
          id: "Conductivity",
          type: "linear",
          scaleLabel: {
            labelString: "Conductivity (Us/cm)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  5: {
    scales: {
      yAxes: [
        {
          id: "Nitrogen",
          type: "linear",
          scaleLabel: {
            labelString: "Nitrogen (mg/kg)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  6: {
    scales: {
      yAxes: [
        {
          id: "Phosphorus",
          type: "linear",
          scaleLabel: {
            labelString: "Phosphorus (mg/kg)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  7: {
    scales: {
      yAxes: [
        {
          id: "Potassium",
          type: "linear",
          scaleLabel: {
            labelString: "Potassium (mg/kg)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  8: {
    scales: {
      yAxes: [
        {
          id: "Ambient Temperature",
          type: "linear",
          scaleLabel: {
            labelString: "Ambient Temperature (ºC)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
  9: {
    scales: {
      yAxes: [
        {
          id: "Light",
          type: "linear",
          scaleLabel: {
            labelString: "Light (Lux)",
            display: true,
          },
          position: "left",
        },
      ],
    },
    responsive: true,
    maintainAspectRatio: false,
  },
};

let lineCharts = [];

function drawGraph(id) {
  const ctx = document.getElementById(`iotChart-${id}`).getContext("2d");
  const myLineChart = new Chart(ctx, {
    type: "line",
    data: chartData[id],
    options: chartOptions[id],
  });
  lineCharts.push(myLineChart);
}

function selectTime(select) {
  console.log(select.value);
}

function selectGraph(select) {
  console.log(select.value);
  let timeSelector = document.getElementById("time-selector");
  let constants = document.getElementById("constant-holder");

  let canvases = document.querySelectorAll(".canvas-wrapper");
  for (let i = 0; i < canvases.length; i++) {
    canvases[i].style.display = "none";
    canvases[i].classList.remove("canvas-active");
  }

  if (select.value == "all") {
    for (let i = 1; i <= canvases.length; i++) {
      canvases[i - 1].style.display = "block";
      drawGraph(i);
      timeSelector.classList.remove("time-selector-active");
      constants.style.display = "flex";
    }
  } else {
    let wrapper = document.getElementById(`canvas-wrapper-${select.value}`);
    wrapper.style.display = "block";
    wrapper.classList.add("canvas-active");
    drawGraph(select.value);
    timeSelector.classList.add("time-selector-active");
    constants.style.display = "none";
  }
}

$(document).ready(() => {
  // if deployed to a site supporting SSL, use wss://
  const protocol = document.location.protocol.startsWith("https")
    ? "wss://"
    : "ws://";
  const webSocket = new WebSocket(protocol + location.host);

  // A class for holding the last N points of telemetry for a device
  class DeviceData {
    constructor(deviceId) {
      this.deviceId = deviceId;
      this.maxLen = 100;
      this.timeData = new Array(this.maxLen);
      this.temperatureData = new Array(this.maxLen);
      this.humidityData = new Array(this.maxLen);
      this.phData = new Array(this.maxLen);
      this.conductivityData = new Array(this.maxLen);
      this.nitrogenData = new Array(this.maxLen);
      this.phosphorusData = new Array(this.maxLen);
      this.potassiumData = new Array(this.maxLen);
      this.ambientTemperatureData = new Array(this.maxLen);
      this.ambientHumidityData = new Array(this.maxLen);
      this.lightData = new Array(this.maxLen);
    }

    addData(
      time,
      temperature,
      humidity,
      ph,
      conductivity,
      nitrogen,
      phosphorus,
      potassium,
      ambientTemp,
      light,
      ambientHumid
    ) {
      this.timeData.push(time);
      this.temperatureData.push(temperature || null);
      this.humidityData.push(humidity || null);
      this.phData.push(ph || null);
      this.conductivityData.push(conductivity || null);
      this.nitrogenData.push(nitrogen || null);
      this.phosphorusData.push(phosphorus || null);
      this.potassiumData.push(potassium || null);
      this.ambientTemperatureData.push(ambientTemp || null);
      this.lightData.push(light || null);
      this.ambientHumidityData.push(ambientHumid || null);

      if (this.timeData.length > this.maxLen) {
        this.timeData.shift();
        this.temperatureData.shift();
        this.humidityData.shift();
        this.phData.shift();
        this.conductivityData.shift();
        this.nitrogenData.shift();
        this.phosphorusData.shift();
        this.potassiumData.shift();
        this.ambientTemperatureData.shift();
        this.lightData.shift();
        this.ambientHumidityData.shift();
      }
    }
  }

  // All the devices in the list (those that have been sending telemetry)
  class TrackedDevices {
    constructor() {
      this.devices = [];
    }

    // Find a device based on its Id
    findDevice(deviceId) {
      for (let i = 0; i < this.devices.length; ++i) {
        if (this.devices[i].deviceId === deviceId) {
          return this.devices[i];
        }
      }

      return undefined;
    }

    getDevicesCount() {
      return this.devices.length;
    }
  }

  const trackedDevices = new TrackedDevices();

  // Define the chart axes

  for (let i = 1; i <= 9; i++) {
    drawGraph(i);
  }

  const newDeviceData = new DeviceData(0);

  const device = new DeviceData(0);

  //   for (let i = 1; i < 10; i++) {
  // 	setTimeout(() => {
  // 		newDeviceData.addData(
  // 			i,
  // 			i,
  // 			i,
  // 			// TODO: Deniz, update these to be the correct keys (in the order of the function params for addData above)
  // 			i,
  // 			i,
  // 			i,
  // 			i,
  // 			i,
  // 			i,
  // 			i,
  // 			i
  // 		  );
  // 	chartData[i].labels = newDeviceData.timeData;
  //     chartData[i].datasets[0].data = newDeviceData.temperatureData;
  //     lineCharts[i-1].update();
  // 	  }, i*1000);
  //   }

  // Manage a list of devices in the UI, and update which device data the chart is showing
  // based on selection

  // When a web socket message arrives:
  // 1. Unpack it
  // 2. Validate it has date/time and temperature
  // 3. Find or create a cached device to hold the telemetry data
  // 4. Append the telemetry data
  // 5. Update the chart UI

  function updateDataOnGraph() {
    chartData[1].datasets[0].data = device.temperatureData;
    chartData[1].labels = device.timeData;

    chartData[2].datasets[0].data = device.humidityData;
    chartData[2].labels = device.timeData;

    chartData[3].datasets[0].data = device.phData;
    chartData[3].labels = device.timeData;

    chartData[4].datasets[0].data = device.conductivityData;
    chartData[4].labels = device.timeData;

    chartData[5].datasets[0].data = device.nitrogenData;
    chartData[5].labels = device.timeData;

    chartData[6].datasets[0].data = device.phosphorusData;
    chartData[6].labels = device.timeData;

    chartData[7].datasets[0].data = device.potassiumData;
    chartData[7].labels = device.timeData;

    chartData[8].datasets[0].data = device.ambientTemperatureData;
    chartData[8].labels = device.timeData;

    chartData[9].datasets[0].data = device.lightData;
    chartData[9].labels = device.timeData;

    for (let i = 0; i < lineCharts.length; i++) {
      lineCharts[i].update();
    }
  }

  generateRand = (min, max) => {
    return Math.random() * (max - min) + min;
  };

  // DENIZ, SET THIS TO FALSE TO USE REAL DATA
  let useFakeData = false;

  setInterval(() => {
    if (useFakeData) {
      let date = new Date().toUTCString();
      device.addData(
        date,
        generateRand(0, 10),
        generateRand(0, 10),
        // TODO: Deniz, update these to be the correct keys (in the order of the function params for addData above)
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10),
        generateRand(0, 10)
      );

      updateDataOnGraph();
    }
  }, 1000);

  webSocket.onmessage = function onMessage(message) {
    if (!useFakeData) {
      try {
        const messageData = JSON.parse(message.data);
        console.log(messageData);

        device.addData(
          messageData.MessageDate,
          messageData.IotData.temperature,
          messageData.IotData.humidity,
          // TODO: Deniz, update these to be the correct keys (in the order of the function params for addData above)
          messageData.IotData.ph,
          messageData.IotData.conductivity,
          messageData.IotData.nitrogen,
          messageData.IotData.phosphorus,
          messageData.IotData.potassium,
          messageData.IotData.ambientTemp,
          messageData.IotData.light,
          messageData.IotData.humidity
        );

        updateDataOnGraph();
      } catch (err) {
        console.error(err);
      }
    }
  };
});
